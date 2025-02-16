#include <stdio.h>
#include <string.h>
#include <ei.h>

int main() {
    int sockfd;
    erlang_pid self;
    ei_cnode ec;
    ei_x_buff msg;
    
    ei_init();
    ei_connect_init(&ec, "cnode", "secret", 0);
    sockfd = ei_connect(&ec, "mynode@iseatz");

    if (sockfd < 0) {
        printf("Failed to connect to Erlang node!\n");
        return 1;
    }

    ei_x_new(&msg);
    ei_x_encode_version(&msg);  // Always encode version first
    ei_x_encode_tuple_header(&msg, 2);  // Sending a tuple {c_node_msg, "Hello from C"}
    ei_x_encode_atom(&msg, "c_node_msg");
    ei_x_encode_string(&msg, "Hello from C");

    ei_reg_send(&ec, sockfd, "my_erl_process", msg.buff, msg.index);
    printf("Message sent to BEAM!\n");
    ei_x_free(&msg);

    return 0;
}


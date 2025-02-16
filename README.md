# cnode-ex

Example usage of [C Nodes](https://www.erlang.org/doc/system/cnode.html) to communicate with Elixir/Erlang.

You'll need two terminals:

## Elixir

```bash
$ iex --sname mynode --cookie secret
iex(mynode@iseatz)1> c "my_process.exs"
[]
```

## C

```bash
$ cc -I/opt/homebrew/opt/erlang/lib/erlang/usr/include -L/opt/homebrew/opt/erlang/lib/erlang/usr/lib -lei main.c
./a.out
Message sent to BEAM!
```

Then you'll see in the Elixir terminal: `Received message: {:c_node_msg, ~c"Hello from C"}`.

## Observations

- Don't forget to change your hostname (`iseatz` here)
- Erlang Interface Guide: https://www.erlang.org/doc/apps/erl_interface/ei_users_guide.html

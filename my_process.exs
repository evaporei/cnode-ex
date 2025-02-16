spawn(fn ->
  Process.register(self(), :my_erl_process)
  receive do
    msg -> IO.inspect(msg, label: "Received message")
  end
end)

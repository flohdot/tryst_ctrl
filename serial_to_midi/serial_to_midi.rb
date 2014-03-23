require 'unimidi'
require 'serialport'


port_str = '/dev/tty.usbmodem1421'
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE


sp =  SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)

begin
  loop do
    resp = sp.gets.chomp
    break if resp.nil?
    if resp[0].to_i > 0
      puts "trigger"
      UniMIDI::Output.open(0) { |output| output.puts(0x90, 36, 100) }
    else
      puts "-"
    end
  end
ensure
  puts "goodbye!"
  sp.close
end


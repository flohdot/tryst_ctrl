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
    triggered = false
    resp = sp.gets.chomp
    break if resp.nil?
    if resp[0].to_i > 0
      puts "trigger"
      triggered = true
      UniMIDI::Output.open(0) { |output| output.puts(0x90, 36, 100) }
    else
      if triggered
        UniMIDI::Output.open(0) { |output| output.puts(0x80, 36, 200) }
        triggered = false
        puts 'STOP'
      else
        puts "-"
      end
    end
  end
ensure
  puts "goodbye!"
  sp.close
end


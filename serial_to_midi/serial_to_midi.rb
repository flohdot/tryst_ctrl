require 'unimidi'
require 'serialport'

@toggle_mode = false

port_str = '/dev/cu.usbmodem1411'
baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE


sp =  SerialPort.new(port_str, baud_rate, data_bits, stop_bits, parity)
prev = 0
@current_notes = []


def emit_trigger(note)
  @current_notes.push(note)
  puts "TRIGGER #{note}"
  keypress(note)
  
  if @toggle_mode
    sleep(2)
    disable()
    puts 'wake'
  end
end

def disable
  until @current_notes.empty?
      n = @current_notes.shift()
      keypress(n) 
      puts "disable #{n}"
  end
end

def keypress(note)
  UniMIDI::Output.open(0) { |output| output.puts(0x90, note, 100) }
  UniMIDI::Output.open(0) { |output| output.puts(0x80, note, 100) }
end


begin
  loop do
    triggered = false
    resp = sp.gets.chomp
    break if resp.nil?
    
    direction = resp[0].to_i

    if direction != prev
      case direction
      when 1
        emit_trigger 36
      when 2
        emit_trigger 37
      when 3
        emit_trigger 38
      when 4
        emit_trigger 39
      else
        disable() unless @toggle_mode
      end

    else
      # puts "same"
    end
    prev = direction
  end
ensure
  puts "goodbye!"
  sp.close
end





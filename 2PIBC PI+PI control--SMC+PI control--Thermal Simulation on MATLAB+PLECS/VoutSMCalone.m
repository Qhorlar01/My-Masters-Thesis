V_out = out.Vout.signals.values;
t     = out.Vout.time;

figure('Name','Output Voltage','NumberTitle','off');

plot(t, V_out, 'LineWidth', 1.5);
grid on;

title('Output Voltage V_{out}');
xlabel('Time (s)');
ylabel('Voltage (V)');
ylim([0 60]);

% Fixed legend syntax:
legend('V_{out}', 'Location', 'best');

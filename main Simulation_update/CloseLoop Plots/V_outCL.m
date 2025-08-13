V_out = out.V_out.signals.values;
t = out.V_out.time;

figure('Name','Output Voltage','NumberTitle','off');

plot(t, V_out, 'LineWidth',1);
grid on;

title('Output Voltage V_{out}');
xlabel('Time (s)');
ylabel('Voltage (volts)');

xlim([0.11732 0.11735]);  % zoom in on interval
ylim([47.7 48.3]);
%xlim([0 3.2e-3]);
% Add a legend
legend('V_{out}');

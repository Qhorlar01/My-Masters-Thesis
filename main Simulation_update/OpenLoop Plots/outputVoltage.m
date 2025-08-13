figure('Name','Output Voltage','NumberTitle','off');

plot(t, V_out, 'LineWidth',1.5);
grid on;

title('Output Voltage V_{out}');
xlabel('Time (s)');
ylabel('Voltage (volts)');

%xlim([0.11732 0.11736]);  % zoom in on interval
%ylim([47.2 48.2]);

% Add a legend
legend('V_{out}');

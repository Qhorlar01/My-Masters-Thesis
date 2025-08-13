V_out1 = out.Vout_PI.signals.values;
V_out2 = out.Vout_SMC.signals.values;
t      = out.tout;

figure('Name','Output Voltage','NumberTitle','off');

plot(t, V_out1, t, V_out2, 'LineWidth', 1.5);   % <- both curves in one call
grid on;

title('Output Voltage V_{out}');
xlabel('Time (s)');
ylabel('Voltage (V)');
xlim([0 0.4]);
ylim([0 80]);

legend({'V_{out} - PI+PI', 'V_{out} - SMC+PI'}, 'Location', 'best');

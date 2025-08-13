figure('Name','coupled inductor current','NumberTitle','off');

plot(t, iL_coupled, 'LineWidth',1.5);
grid on;

title('Directly Coupled Inductor Current');
xlabel('Time (s)');
ylabel('Current (A)');

xlim([0.17624 0.17628]);  % zoom in on interval

% Add a legend
legend('iL1','iL2');

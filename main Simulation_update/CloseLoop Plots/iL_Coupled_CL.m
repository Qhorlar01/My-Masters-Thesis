figure('Name','Close-Loop coupled inductor current','NumberTitle','off');

plot(t, iL_coupled, 'LineWidth',1);
grid on;

title('Close-Loop Coupled Inductor Current iL_{coupled}');
xlabel('Time (s)');
ylabel('Current (A)');

%xlim([0.17624 0.17632]);  % zoom in on interval
xlim([0 2.2e-3]);

% Add a legend
legend('iL1','iL2');

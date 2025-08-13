figure('Name','coupled inductor current','NumberTitle','off');

plot(t, iL_coupled, 'LineWidth',1);
grid on;

title('Coupled Inductor Current iL_{coupled}');
xlabel('Time (s)');
ylabel('Current (A)');

%xlim([0.17624 0.17632]);  % zoom in on interval

% Add a legend
legend('iL1','iL2');

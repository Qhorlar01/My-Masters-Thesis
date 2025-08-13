figure('Name','coupled inductor input current','NumberTitle','off');
plot(t, iL_in, 'LineWidth',1.5);
grid on;

title('Coupled Inductor input Current iL_{in}');
xlabel('Time (s)');
ylabel('Current (A)');
xlim([0.17624 0.17632]);  % zoom in on interval

% Add a legend
legend('iL_{in}');

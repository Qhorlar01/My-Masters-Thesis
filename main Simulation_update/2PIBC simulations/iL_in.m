clear plot
clear figure

figure('Name','Test','NumberTitle','off');

plot(t, iL_in, 'LineWidth',1.5);
grid on;

title('UnCoupled Inductor input Current iL_{in}');
xlabel('Time (s)');
ylabel('Current (A)');

xlim([0.37640 0.37644]);  % zoom in on interval

% Add a legend
legend('iL_{in}');

figure('Name','Phse 1 Inductor Current and Switch signals','NumberTitle','off');

% Plot all signals on one axes
plot(t, iL1, 'LineWidth',1.5); 
hold on;
plot(t, S1+12, 'LineWidth',1.5);
hold on;
plot(t, S2+10, 'LineWidth',1.5);
hold off;

grid on;
title('Inductor Current, S1, and S2 on the Same Axes');
xlabel('Time (s)');
ylabel('Amplitude');
xlim([0.103040, 0.103060]);   % zoom in on specific time interval
legend('iL1','S1','S2');

% Optional: adjust figure size
%set(gcf, 'Position', [100 100 700 600]);

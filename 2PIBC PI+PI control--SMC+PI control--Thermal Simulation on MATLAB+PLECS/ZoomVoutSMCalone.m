V_out = out.Vout.signals.values;
t     = out.Vout.time;

figure('Name','Output Voltage','NumberTitle','off');

% --- Main plot ---
plot(t, V_out, 'LineWidth', 1.5);
grid on;
title('Output Voltage V_{out}');
xlabel('Time (s)');
ylabel('Voltage (V)');  
xlim([0 0.5]);
ylim([0 60]);
legend('V_{out}', 'Location', 'best');

% --- Inset #2: 0–0.025 s ---
axZoom2 = axes('Position',[0.097 0.55 0.30 0.30], 'Box','on');
plot(axZoom2, t, V_out, 'LineWidth',1.2); hold(axZoom2,'on');
grid(axZoom2,'on');
xlim(axZoom2,[0     0.01]);
title(axZoom2,'Zoom: 0–0.01 s');
legend(axZoom2,'V_{out}','Location','best');

% --- Inset #3: 0.06–0.0601 s ---
axZoom3 = axes('Position',[0.40 0.15 0.30 0.30], 'Box','on');
plot(axZoom3, t, V_out, 'LineWidth',1.2); hold(axZoom3,'on');
grid(axZoom3,'on');
xlim(axZoom3,[0.06 0.0601]);
title(axZoom3,'Zoom: 0.06–0.0601 s');
legend(axZoom3,'V_{out}','Location','best');

% --- Inset #1: 0.3–0.325 s ---
axZoom1 = axes('Position',[0.60 0.55 0.30 0.30], 'Box','on');
plot(axZoom1, t, V_out, 'LineWidth',1.2); hold(axZoom1,'on');
grid(axZoom1,'on');
xlim(axZoom1,[0.3   0.3001]);
title(axZoom1,'Zoom: 0.3–0.3001 s');
legend(axZoom1,'V_{out}','Location','best');






Vout = out.V_out.signals.values;
t       = out.tout;

figure('Name','Test','NumberTitle','off');

% --- Main axes ---
axMain = axes;                         
plot(axMain, t, Vout, 'LineWidth',2); hold(axMain,'on');
grid(axMain,'on');
title(axMain,'Output Voltage V_{out}');
xlabel(axMain,'Time (s)');
ylabel(axMain,'Voltage (V)');
legend(axMain,{'V_{out}'}, 'Location','best');


% -------------------------------------------------------------------------

% --- Inset (zoom) axes ---
axZoom = axes('Position',[0.60 0.55 0.30 0.30]);
plot(axZoom, t, Vout, 'LineWidth',1.5); hold(axZoom,'on');
grid(axZoom,'on');
xlim(axZoom,[0.37640 0.37644]);
title(axZoom,'Zoom');
legend(axZoom,{'V_{out}'}, 'Location','best');
set(axZoom,'Box','on');

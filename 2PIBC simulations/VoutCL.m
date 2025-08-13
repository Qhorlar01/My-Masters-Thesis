Vout = out.V_out.signals.values;
t    = out.tout;

figure('Name','Test','NumberTitle','off');


axMain = axes;                         
plot(axMain, t, Vout, 'LineWidth',2); hold(axMain,'on');
grid(axMain,'on');
title(axMain,'Output Voltage V_{out}');
xlabel(axMain,'Time (s)');
ylabel(axMain,'Voltage (V)');
legend(axMain,{'V_{out}'}, 'Location','southeast');


axZoom1 = axes('Position',[0.60 0.55 0.30 0.30]);
plot(axZoom1, t, Vout, 'LineWidth',1.5); hold(axZoom1,'on');
grid(axZoom1,'on');
xlim(axZoom1,[0.37640 0.37644]);
title(axZoom1,'Steady state Zoom');
legend(axZoom1,{'V_{out}'}, 'Location','southeast');
set(axZoom1,'Box','on');


axZoom2 = axes('Position',[0.15 0.15 0.30 0.30]); 
plot(axZoom2, t, Vout, 'LineWidth',1.5); hold(axZoom2,'on');
grid(axZoom2,'on');
xlim(axZoom2,[0 3.5e-3]);
title(axZoom2,'Startup Zoom');
legend(axZoom2,{'V_{out}'}, 'Location','southeast');
set(axZoom2,'Box','on');

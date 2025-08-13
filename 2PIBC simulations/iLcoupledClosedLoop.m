iL_all = out.iL_coupled.signals.values;   % size N×2
t       = out.tout;

iL1 = iL_all(:,1);
iL2 = iL_all(:,2);

figure('Name','Test','NumberTitle','off');

% --- Main axes ---
axMain = axes;                         
plot(axMain, t, iL1, 'LineWidth',1.5); hold(axMain,'on');
plot(axMain, t, iL2, 'LineWidth',1.5); hold(axMain,'off');
grid(axMain,'on');
title(axMain,'Coupled Inductor Input Current iL_{coupled}');
xlabel(axMain,'Time (s)');
ylabel(axMain,'Current (A)');
legend(axMain,{'iL1','iL2'}, 'Location','best');


% --- Inset #1 (mid‐sim zoom) ---
axZoom1 = axes('Position',[0.60 0.55 0.30 0.30]);
plot(axZoom1, t, iL1, 'LineWidth',1.2); hold(axZoom1,'on');
plot(axZoom1, t, iL2, 'LineWidth',1.2); hold(axZoom1,'off');
grid(axZoom1,'on');
xlim(axZoom1,[0.37640 0.37644]);
title(axZoom1,'Zoom (steady‑state)');
legend(axZoom1,{'iL1','iL2'}, 'Location','best');
set(axZoom1,'Box','on');


% --- Inset #2 (startup zoom) ---
axZoom2 = axes('Position',[0.15 0.55 0.30 0.30]);   % move to upper left
plot(axZoom2, t, iL1, 'LineWidth',1.2); hold(axZoom2,'on');
plot(axZoom2, t, iL2, 'LineWidth',1.2); hold(axZoom2,'off');
grid(axZoom2,'on');
xlim(axZoom2,[0 2.5e-3]);
title(axZoom2,'Startup Zoom');
legend(axZoom2,{'iL1','iL2'}, 'Location','northeast');
set(axZoom2,'Box','on');

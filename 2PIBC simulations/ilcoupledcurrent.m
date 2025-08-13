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


% -------------------------------------------------------------------------

% --- Inset (zoom) axes ---
axZoom = axes('Position',[0.60 0.55 0.30 0.30]);
plot(axZoom, t, iL1, 'LineWidth',1.2); hold(axZoom,'on');
plot(axZoom, t, iL2, 'LineWidth',1.2); hold(axZoom,'off');
grid(axZoom,'on');
xlim(axZoom,[0.37640 0.37644]);
title(axZoom,'Zoom');
legend(axZoom,{'iL1','iL2'}, 'Location','best');
set(axZoom,'Box','on');

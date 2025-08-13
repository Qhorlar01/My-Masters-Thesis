iL_in = out.I_in.signals.values;
t      = out.tout;

figure('Name','Test','NumberTitle','off');

% --- Main axes ---
axMain = axes;
plot(axMain, t, iL_in, 'b', 'LineWidth',1.5);  % Blue color
grid(axMain,'on');
title(axMain,'UnCoupled Inductor Input Current iL_{in}');
xlabel(axMain,'Time (s)');
ylabel(axMain,'Current (A)');
legend(axMain,'iL_{in}');

% ----- Ripple label ----------------------------------------------------
text(axMain, 0.05, 0.90, 'Current ripple = 1.6 %', ...
     'Units','normalized', ...
     'FontSize',12, ...
     'FontWeight','bold', ...
     'BackgroundColor','white', ...
     'Margin',4);
% -----------------------------------------------------------------------

% --- Inset (zoom) axes ---
axZoom = axes('Position',[0.60 0.55 0.30 0.30]);
plot(axZoom, t, iL_in, 'g', 'LineWidth',1.2);   % Red color
grid(axZoom,'on');
xlim(axZoom,[0.37640 0.37644]);
title(axZoom,'Zoom');
set(axZoom,'Box','on');

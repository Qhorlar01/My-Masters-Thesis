%% ---------------- RAW DATA ---------------------------------------------
V_out1 = out.Vout_PI.signals.values;
V_out2 = out.Vout_SMC.signals.values;
t      = out.tout;

%% ---------------- MAIN FIGURE ------------------------------------------
figure('Name','Output Voltage','NumberTitle','off');
plot(t, V_out1, t, V_out2, 'LineWidth',1);
grid on
title('Output Voltage V_{out}');
xlabel('Time (s)');  ylabel('Voltage (V)');
xlim([0.3 0.5]);  ylim([0 70]);
legend({'V_{out} - PI+PI','V_{out} - SMC+PI'},'Location','best');

axMain = gca;                 % handle to main axes
hold(axMain,'on')

%% ---------------- ZOOM INSET ( **inside** the main plot ) --------------
% size of inset as a fraction of the main axes
wFrac = 0.32;          % 0.32 ↔ 32 % of main width
hFrac = 0.32;          % 0.32 ↔ 32 % of main height
pad   = 0.015;         % small padding from the axes borders

% compute absolute (figure-normalized) position for the inset
axPos = axMain.Position;                % [left bottom width height]
insetW = axPos(3)*wFrac;
insetH = axPos(4)*hFrac;
insetX = axPos(1)+axPos(3)-insetW-pad;  % upper-right corner
insetY = axPos(2)+axPos(4)-insetH-pad;

axZoom = axes('Position',[insetX insetY insetW insetH]);
copyobj(allchild(axMain),axZoom);       % duplicate both curves

xlim(axZoom,[0.3995 0.404]);
ylim(axZoom,[ ...
     min(V_out2(t>0.395 & t<0.404))-1 , ...
     max(V_out1(t>0.395 & t<0.404))+1 ]);
grid(axZoom,'on');  box(axZoom,'on')
set(axZoom,'FontSize',7)
title(axZoom,'Zoom: 0.3995–0.404 s')

%% ---------------- ARROW -------------------------------------------------
pt   = [0.401 , V_out1(find(t>=0.401,1))];    % representative point
pFig = data2norm(axMain,pt);                  % convert → figure units

annotation('textarrow', ...
           [pFig(1)  insetX+insetW/2], ...
           [pFig(2)  insetY], ...
           'HeadStyle','vback2','String','');

%% ---------------- SETTLING-TIME NUMBERS ---------------------------------
idxWin = t >= 0.395 & t <= 0.404;
Vss1   = mean(V_out1(idxWin));
Vss2   = mean(V_out2(idxWin));

band1 = [0.98*Vss1 1.02*Vss1];
band2 = [0.98*Vss2 1.02*Vss2];

t1 = t(idxWin & V_out1>=band1(1) & V_out1<=band1(2));
t2 = t(idxWin & V_out2>=band2(1) & V_out2<=band2(2));

settle_PI  = t1(1) - 0.395;
settle_SMC = t2(1) - 0.395;

fprintf('Settling time: PI+PI = %.4f s,  SMC+PI = %.4f s\n', ...
        settle_PI, settle_SMC);

%% ---------------- HELPER FUNCTION --------------------------------------
function p = data2norm(ax,pt)
%DATA2NORM  Convert one data-space point to figure-normalized units.
   axPos = get(ax,'Position');          % [left bottom width height]
   axX   = get(ax,'XLim');  axY = get(ax,'YLim');
   p(1)  = axPos(1) + axPos(3)*(pt(1)-axX(1))/diff(axX);
   p(2)  = axPos(2) + axPos(4)*(pt(2)-axY(1))/diff(axY);
end

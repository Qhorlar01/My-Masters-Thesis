%% --- your original code -------------------------------------------------
V_out1 = out.Vout_PI.signals.values;
V_out2 = out.Vout_SMC.signals.values;
t      = out.tout;

figure('Name','Output Voltage','NumberTitle','off');
plot(t, V_out1, t, V_out2, 'LineWidth', 1);     % both curves
grid on;
title('Output Voltage V_{out}');
xlabel('Time (s)');  ylabel('Voltage (V)');
xlim([0 0.4]);  ylim([0 70]);
legend({'V_{out} - PI+PI','V_{out} - SMC+PI'},'Location','best');

axMain = gca;            % keep a handle to the main axes
hold on
xline([0.1 0.3],'k--')   % (optional) vertical guide lines
%% ------------------------------------------------------------------------

%% -------- 1st ZOOM: load change at 0.10 s --------------------------------
% inset location (in figure-normalized coordinates)
ax1 = axes('Position',[0.20 0.55 0.22 0.30]);    % left, bottom, width, height
copyobj(allchild(axMain),ax1);                   % copy both traces
xlim(ax1,[0.09 0.11]);                           % narrow time window
ylim(ax1,[min(V_out2(t>0.09 & t<0.11))-1, ...
          max(V_out1(t>0.09 & t<0.11))+1]);      % tight Y-range
grid(ax1,'on');  box(ax1,'on')
set(ax1,'FontSize',7)
title(ax1,'Zoom @ 0.10 s')

% draw arrow from main curve to inset
pt = [0.10, V_out1(find(t>=0.10,1))];            % point to highlight
p_fig = data2norm(axMain,pt);                    % helper below
annotation('textarrow', ...
           [p_fig(1) ax1.Position(1)+ax1.Position(3)], ...
           [p_fig(2) ax1.Position(2)+ax1.Position(4)/2], ...
           'String','', 'HeadStyle','vback2');

%% -------- 2nd ZOOM: load change at 0.30 s --------------------------------
ax2 = axes('Position',[0.62 0.17 0.22 0.30]);    % adjust location as you like
copyobj(allchild(axMain),ax2);
xlim(ax2,[0.29 0.31]);
ylim(ax2,[min(V_out2(t>0.29 & t<0.31))-1, ...
          max(V_out1(t>0.29 & t<0.31))+1]);
grid(ax2,'on'); box(ax2,'on')
set(ax2,'FontSize',7)
title(ax2,'Zoom @ 0.30 s')

pt = [0.30, V_out1(find(t>=0.30,1))];
p_fig = data2norm(axMain,pt);
annotation('textarrow', ...
           [p_fig(1) ax2.Position(1)], ...
           [p_fig(2) ax2.Position(2)+ax2.Position(4)], ...
           'String','', 'HeadStyle','vback2');

%% -------- helper: convert data-space → figure-normalized -----------------
function p = data2norm(ax,pt)
   % returns [x y] of a data point in *figure-normalized* units
   ax_pos = get(ax,'Position');          % axes position in figure units
   ax_x = get(ax,'XLim');  ax_y = get(ax,'YLim');
   p(1) = ax_pos(1) + ax_pos(3)*(pt(1)-ax_x(1))/diff(ax_x);
   p(2) = ax_pos(2) + ax_pos(4)*(pt(2)-ax_y(1))/diff(ax_y);
end

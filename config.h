// Appearance
static const unsigned int borderpx          = 3;  // Border pixel of windows
static const unsigned int snap              = 32; // snap pixel

static const int showbar                    = 1;  // 0 means no bar
static const int topbar                     = 1;  // 0 means bottom bar

static const char *fonts[]                  = {"NotoSansMono Nerd Font:size=11"};

static const char col_prefered_gray[]       = "#595959";

static const char col_border_selected[]     = "#202020"; // Border colour of selected window
static const char col_border_unselected[]   = "#000000"; // Border colour of unselected window
static const char col_tag_selected[]        = "#202020"; // Selected tag colour
static const char col_tag_name_selected[]   = "#ffffff"; // Name colour of selected tag
static const char col_tag_name_unselected[] = "#595959"; // Name colour of unselected tag
static const char col_bar[]                 = "#000000"; // Bar colour
static const char col_bar_text[]            = "#000000"; // Bar colour



static const char *colors[][3]      = {
	// -------------- fg                        bg                border
	[SchemeNorm]    = {col_tag_name_unselected, col_bar,          col_border_unselected},
	[SchemeSel]     = {col_tag_name_selected,   col_tag_selected, col_border_selected},
	[SchemeStatus]  = {col_bar_text,            col_bar,          col_tag_name_unselected},
};



// Tagging
static const char *tags[] = { "", "", "", "", ""};

static const Rule rules[] = {

	// xprop(1):
	//  WM_CLASS(STRING) = instance, class
	//  WM_NAME(STRING) = title
	// 

	// Class      instance    title       tags mask     isfloating   monitor
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};



// Layout(s)
static const float mfact     = 0.55; // Factor of master area size [0.05..0.95]
static const int nmaster     = 1;    // Number of clients in master area
static const int resizehints = 0;    // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1; // 1 will force focus on the fullscreen window

static const Layout layouts[] = {
	// Symbol     arrange function
	{ "",       tile },    // First entry is default
	{ "",      NULL },    // No layout function means floating behavior
	{ "",      monocle },
};



#define MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }



static const char *termcmd[]  = {"urxvt", NULL};
static const char *browsercmd[]  = {"firefox", NULL};



static Key keys[] = {
    // Macros for programs
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },           // Spawn terminal
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = browsercmd } },        // Spawn browser
	{ MODKEY,                       XK_x,      spawn,          SHCMD("tmux kill-server") }, // Kills all tmux windows; ctrl+d to kill one tmux window

    // Macros for control
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	//{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

    // Tags/WS
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
};



// Button definitions
// Click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkClientWin, or ClkRootWin
static Button buttons[] = {
	// Click                event mask      button          function        argument
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


color desert                    "背景颜色
set number                      "显示行号
set tabstop=4                   "Tab跳数
"Toggle Menu and Toolbar     隐藏菜单栏和工具栏
set hlsearch   			"高亮查找结果
syntax enable     		"打开语法高亮
syntax on			"打开语法高亮
set showmatch 			"设置括号匹配
set smartindent			"只能对齐
set autoindent			"自动对齐
set ai!				"自动缩进
set cin       "C语言缩进

"Toggle Menu and Toolbar
set guioptions-=m
set guioptions-=T
map <silent> <F2> :if &guioptions =~# 'T' <Bar>
        \set guioptions-=T <Bar>
        \set guioptions-=m <bar>
    \else <Bar>
        \set guioptions+=T <Bar>
        \set guioptions+=m <Bar>
    \endif<CR

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

"复制粘贴设置
vmap <C-c> "+yi 
vmap <C-x> "+c 
vmap <C-v> c<ESC>"+p 
imap <C-v> <ESC>"+pa 

"Toggle Menu and Toolbar      "F2控制菜单工具栏
set guioptions-=m
set guioptions-=T
map <silent> <F2> :if &guioptions =~# 'T' <Bar>
        \set guioptions-=T <Bar>
        \set guioptions-=m <bar>
    \else <Bar>
        \set guioptions+=T <Bar>
        \set guioptions+=m <Bar>
    \endif<CR


//http://blog.csdn.net/lonfee88/article/details/6325246

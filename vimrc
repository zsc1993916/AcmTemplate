"""""""""""""""""""""""""""""""""""""
""""""""""""""" Zo's vimrc"""""""""""
"解决windows下的中文乱码问题
"set fileencodings=utf-8,gbk,chinese  
" 解决中文菜单乱码  
"set langmenu=zh_CN.utf-8  
"source $VIMRUNTIME/delmenu.vim  
"source $VIMRUNTIME/menu.vim  
"解决console输出乱码  
"language messages zh_CN.utf-8


" 文本格式和排版 
color darkblue                   "背景颜色
set number                      "显示行号
set tabstop=4                   "Tab跳数
set hlsearch   			"高亮查找结果
syntax enable     		"打开语法高亮
syntax on			"打开语法高亮
set showmatch 			"设置括号匹配
set autoindent			"自动对齐
set ai!				"自动缩进
set cin                         "c语言缩进
set formatoptions=tcrqn     " 自动格式化   
set smartindent  		 "为C程序提供自动缩进  
set cindent    			" 使用C样式的缩进    
set softtabstop=4      "统一缩进为4 
set shiftwidth=4  
set noexpandtab    " 不要用空格代替制表符 
set wrap        " 不要换行  
set smarttab      " 在行和段开始处使用制表符 
set guifont=Consolas:h13  " 习惯的字体

"复制粘贴设置
vmap <C-c> "+yi 
vmap <C-x> "+c 
vmap <C-v> c<ESC>"+p 
imap <C-v> <ESC>"+pa 

"显示命令
set showcmd  
" 命令行（在状态行下）的高度，默认为1，这里是2  
set cmdheight=1 


" 快捷键设定 
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""  
" C的编译和运行  
map <F5> :call CompileRunGcc()<CR>  
func! CompileRunGcc()  
exec "w"  
exec "!gcc % -o %<"  
exec "! ./%<"  
endfunc  
" C++的编译和运行  
map <F6> :call CompileRunGpp()<CR>  
func! CompileRunGpp()  
exec "w"  
exec "!g++ % -o %<"  
exec "! ./%<"   
endfunction  
" Python的运行  
map <F8> :call RunPython()<CR>  
func! RunPython()   
    let mp = &makeprg   
    let ef = &errorformat   
    let exeFile = expand("%:t")   
    setlocal makeprg=python\ -u   
    set efm=%C\ %.%#,%A\ \ File\ \"%f\"\\,\ line\ %l%.%#,%Z%[%^\ ]%\\@=%m   
    silent make %   
    copen   
    let &makeprg     = mp   
    let &errorformat = ef   
endfunction

"Toggle Menu and Toolbar  
set guioptions-=m
set guioptions-=T
map <silent> <F2> :if &guioptions =~# 'T' <Bar>
        \set guioptions-=T <Bar>
        \set guioptions-=m <bar>
    \else <Bar>
        \set guioptions+=T <Bar>
        \set guioptions+=m <Bar>
    \endif<CR>



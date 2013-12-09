"----Encoding setting----
set encoding=utf-8              "编码设置
set ffs=unix,dos,mac            "设置保存系统格式
set langmenu=zh_CN.utf-8        "中文菜单界面
language messages zh_CN.utf-8   "中文提示界面

"----Basic function----
set nu                          "显示行号
set nowb                        "禁止自动保存
set nocp                        "去除vi一致性
set ruler                       "显示标尺
set nobackup                    "禁止缓冲保存
set showmatch                   "符号自动匹配
set incsearch                   "搜索增强模式
set noswapfile                  "去除swap文件
set history=700                 "设置最大历史记录
set autochdir                   "设置为当前文件目录
set backspace=indent,eol,start  "去除键设置


"----Mouse setting----
set mouse=a                     "开启鼠标模式
set selection=exclusive 
set selectmode=mouse,key

"----Indent habit----
set nowrap                      "不自动换行
set cindent                     "C格式缩进
set smarttab                    "智能tab
set expandtab                   "tab用空格代替
set tabstop=4                   "一个tab=4个字符
set autoindent                  "自动缩进
set smartindent                 "智能缩进
set backspace=2                 "
set shiftwidth=4                "
set softtabstop=4               "按一次tab 前进4个字符
set textwidth=80                "超过80个字符自动换行

"---Auto Complete----
"三种括号自动补全
inoremap { {<CR>}<ESC>kA<CR>
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap " ""<ESC>i
inoremap ' ''<ESC>i
inoremap < <><ESC>i
"一键ctrl+s保存
map <C-s> <ESC>:wall<CR>
"一键F9保存
map <F9> <ESC>:wall<CR>
"一键分屏打开in.txt/out.txt并自动调整大小
map <F10> <ESC>:vs out.txt<CR><C-w>L<ESC>:sp in.txt<CR><C-w>h<C-w>20><CR>
"一键运行run.bat批处理
map <F5> <ESC>:! run.bat<CR>

"----Theme setting----
syntax on                       "开启高亮
"syntax enable                  "使用高亮
colorscheme darkblue              "主题配色
set background=dark             "背景暗色
set guifont=Source\ Code\ Pro\ ExtraLight:h15          "字体设置

"----Autoread the text----  
filetype on                     "自动识别文件类型
if exists("&autoread")            "自动读取修改文件
    set autoread
endif

"----Open with maxwindow in Win32----
if has('win32')
    au GUIEnter * simalt ~x
else
    au GUIEnter * call MaximizeWindow()
endif

function! MaximizeWindow()
    silent !wmctrl -r :ACTIVE: -b add,maximized_vert,maximized_horz
endfunction

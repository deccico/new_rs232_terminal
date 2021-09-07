md bak
cd bak
md %1
cd..
echo  d | xcopy *.bpr bak\%1 
echo  d | xcopy *.cpp bak\%1
xcopy *.exe bak\%1
xcopy *.txt bak\%1
xcopy *.hpp bak\%1
xcopy *.h bak\%1
xcopy *.dfm bak\%1
xcopy *.dpr bak\%1
xcopy *.pas bak\%1
xcopy *.ini bak\%1
rem xcopy *.exe bak\%1
xcopy *.db bak\%1
xcopy *.bat bak\%1
xcopy *.mb bak\%1
xcopy *.px bak\%1
xcopy *.res bak\%1
xcopy *.val bak\%1
xcopy *.x* bak\%1
xcopy *.y* bak\%1
xcopy *.bmp bak\%1
xcopy *.gif bak\%1
xcopy *.ico bak\%1
xcopy *.jpg bak\%1
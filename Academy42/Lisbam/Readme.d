El objetivo de este proyecto es familiarizarse con el lenguaje ensamblador, reproduciendo algunas de las funciones mas comunes, reescribiendolas en asm64 bits, sintaxis Intel.
(Al principio parece indio pero luego se va entendiendo todo cuando lees varias veces las referencias)

Requisito tener instalado:

rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && export PATH=$HOME/.brew/bin:$PATH && brew update && echo "export PATH=$HOME/.brew/bin:$PATH" >> ~/.zshrc

brew install nasm

REFERENCÍAS:
https://www.notion.so/Assembler-1f586123899c4d90ac6f8507e25447a1
http://cv.uoc.edu/annotation/8255a8c320f60c2bfd6c9f2ce11b2e7f/619469/PID_00218273/PID_00218273.html#w31aac15c13b9c25
https://medium.com/nabucodonosor-editorial/registros-x86-2e3d5e936f16
https://medium.com/nabucodonosor-editorial/saltos-en-ensamblador-x86-a94474f58ad1
https://medium.com/@tirkarp/understanding-x86-assembly-5d7d637efb5

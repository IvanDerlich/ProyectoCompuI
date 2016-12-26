#!/bin/sh

#Scrip para debuggear

binario=$(basename `dirname $PWD`)

valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all  ../Binaries/$binario sdfg sdfg

#Valgrind: "For counts of detected and suppressed errors, rerun with: -v"
#habilitar valgrind para testeo de errores segun el parametro de entrada de este archivo, que valgrind sea un flag, strace tambien

# Detalle importante: Segun este enlace de stackoverflow 
# http://stackoverflow.com/questions/30376601/valgrind-memory-still-reachable-with-trivial-program-using-iostream
# La libreria iostream tiene un bug que no borra informacion que aloca y Valgrind acusa este error
# Estoy debiendo probar si sacando la libreria el error se va




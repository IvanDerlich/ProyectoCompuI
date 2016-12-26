#Makefile hecho por Ivan Derlich, si lo queres usar no te cobro, gato
#Los comentarios estan en un archivo aparte
#Tareas
#	Que funcione el build log
#	Aprender que necesidad hay de usar los archivos .o
#	Prebuild options: 
#		Si no existe el directorio Binaries, crearl

#Parametros de configuracion
INC_DIR = ../Headers #directorio para el comando "#include"
SRC_DIR = ../Sources
#BIN_DIR = ../Binaries
BIN_DIR = /var/www/cgi-bin
CFLAGS = -Wall -Wno-write-strings -Werror -g -I$(INC_DIR)
LIBS =	-lmysqlcppconn -lmysqlcppconn-static 

#Comentario 3 (sobre flags)
#---------------------------

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)	#Comentario 1
TARGET = $(shell basename  $(shell dirname $(shell pwd))) #Comentario 2	    
	
all: 
	g++ $(CFLAGS)  $(SOURCES) -o $(BIN_DIR)/$(TARGET) $(LIBS)	

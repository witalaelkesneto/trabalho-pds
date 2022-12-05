CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main

main: sistema
	$(CC) $(CFLAGS)  build/tetoException.o build/gastoException.o build/hospitalExisteException.o build/hospitalNaoExisteException.o build/tipoInvalidoException.o build/senhaErradaException.o build/usuarioNaoExisteException.o build/usuarioExisteException.o build/menuException.o build/cidadao.o build/secretario.o build/prefeito.o build/hospital.o build/usuario.o build/sistema.o src/main.cpp -o $(TARGET)

sistema: cidadao secretario prefeito hospital menuException usuarioNaoExisteException usuarioExisteException senhaErradaException tipoInvalidoException
	$(CC) $(CFLAGS) -c src/sistema.cpp -o build/sistema.o

cidadao: usuario
	$(CC) $(CFLAGS) -c src/cidadao.cpp -o build/cidadao.o

secretario: usuario gastoException
	$(CC) $(CFLAGS) -c src/secretario.cpp -o build/secretario.o

prefeito: usuario hospitalExisteException gastoException tetoException
	$(CC) $(CFLAGS) -c src/prefeito.cpp -o build/prefeito.o

usuario: menuException usuarioExisteException hospitalNaoExisteException
	$(CC) $(CFLAGS) -c src/usuario.cpp -o build/usuario.o

hospital:
	$(CC) $(CFLAGS) -c src/hospital.cpp -o build/hospital.o

menuException:
	$(CC) $(CFLAGS) -c exceptions/menuException.cpp -o build/menuException.o

usuarioNaoExisteException:
	$(CC) $(CFLAGS) -c exceptions/usuarioNaoExisteException.cpp -o build/usuarioNaoExisteException.o

usuarioExisteException:
	$(CC) $(CFLAGS) -c exceptions/usuarioExisteException.cpp -o build/usuarioExisteException.o

senhaErradaException:
	$(CC) $(CFLAGS) -c exceptions/senhaErradaException.cpp -o build/senhaErradaException.o

tipoInvalidoException:
	$(CC) $(CFLAGS) -c exceptions/tipoInvalidoException.cpp -o build/tipoInvalidoException.o

hospitalNaoExisteException:
	$(CC) $(CFLAGS) -c exceptions/hospitalNaoExisteException.cpp -o build/hospitalNaoExisteException.o

hospitalExisteException:
	$(CC) $(CFLAGS) -c exceptions/hospitalExisteException.cpp -o build/hospitalExisteException.o

gastoException:
	$(CC) $(CFLAGS) -c exceptions/gastoException.cpp -o build/gastoException.o

tetoException:
	$(CC) $(CFLAGS) -c exceptions/tetoException.cpp -o build/tetoException.o

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)

doxy:
	doxygen doxyconfig
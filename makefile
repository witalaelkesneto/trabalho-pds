CC := g++
SRCDIR := src
BUILDDIR := build
EXCEPTIONSDIR := exceptions
TESTSDIR := tests
LIBDIR := third_party
DOCTEST := $(LIBDIR)/doctest.h
TARGET := main
CFLAGS := -g -Wall -O3 -std=c++11 -I include/
IFLAGS := -I $(LIBDIR) -I include

all: main tests

main: sistema
	$(CC) $(CFLAGS) $(BUILDDIR)/* $(SRCDIR)/main.cpp -o $(TARGET)

sistema: cidadao secretario prefeito hospital menuException usuarioNaoExisteException usuarioExisteException senhaErradaException tipoInvalidoException
	$(CC) $(CFLAGS) -c $(SRCDIR)/sistema.cpp -o $(BUILDDIR)/sistema.o

cidadao: usuario
	$(CC) $(CFLAGS) -c $(SRCDIR)/cidadao.cpp -o $(BUILDDIR)/cidadao.o

secretario: usuario gastoException
	$(CC) $(CFLAGS) -c $(SRCDIR)/secretario.cpp -o $(BUILDDIR)/secretario.o

prefeito: usuario hospitalExisteException gastoException tetoException
	$(CC) $(CFLAGS) -c $(SRCDIR)/prefeito.cpp -o $(BUILDDIR)/prefeito.o

usuario: menuException usuarioExisteException hospitalNaoExisteException
	$(CC) $(CFLAGS) -c $(SRCDIR)/usuario.cpp -o $(BUILDDIR)/usuario.o

hospital:
	$(CC) $(CFLAGS) -c $(SRCDIR)/hospital.cpp -o $(BUILDDIR)/hospital.o

menuException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/menuException.cpp -o $(BUILDDIR)/menuException.o

usuarioNaoExisteException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/usuarioNaoExisteException.cpp -o $(BUILDDIR)/usuarioNaoExisteException.o

usuarioExisteException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/usuarioExisteException.cpp -o $(BUILDDIR)/usuarioExisteException.o

senhaErradaException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/senhaErradaException.cpp -o $(BUILDDIR)/senhaErradaException.o

tipoInvalidoException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/tipoInvalidoException.cpp -o $(BUILDDIR)/tipoInvalidoException.o

hospitalNaoExisteException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/hospitalNaoExisteException.cpp -o $(BUILDDIR)/hospitalNaoExisteException.o

hospitalExisteException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/hospitalExisteException.cpp -o $(BUILDDIR)/hospitalExisteException.o

gastoException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/gastoException.cpp -o $(BUILDDIR)/gastoException.o

tetoException:
	$(CC) $(CFLAGS) -c $(EXCEPTIONSDIR)/tetoException.cpp -o $(BUILDDIR)/tetoException.o

tests: hospitalTest cidadaoTest secretarioTest prefeitoTest sistemaTest

hospitalTest: hospital
	$(CC) $(IFLAGS) $(DOCTEST) $(BUILDDIR)/hospital.o $(TESTSDIR)/$(SRCDIR)/hospitalTest.cpp -o $(TESTSDIR)/$(BUILDDIR)/hospitalTest

cidadaoTest: cidadao
	$(CC) $(IFLAGS) $(DOCTEST) $(BUILDDIR)/* $(TESTSDIR)/$(SRCDIR)/cidadaoTest.cpp -o $(TESTSDIR)/$(BUILDDIR)/cidadaoTest

secretarioTest: secretario
	$(CC) $(IFLAGS) $(DOCTEST) $(BUILDDIR)/* $(TESTSDIR)/$(SRCDIR)/secretarioTest.cpp -o $(TESTSDIR)/$(BUILDDIR)/secretarioTest

prefeitoTest: prefeito
	$(CC) $(IFLAGS) $(DOCTEST) $(BUILDDIR)/* $(TESTSDIR)/$(SRCDIR)/prefeitoTest.cpp -o $(TESTSDIR)/$(BUILDDIR)/prefeitoTest

sistemaTest: sistema
	$(CC) $(IFLAGS) $(DOCTEST) $(BUILDDIR)/* $(TESTSDIR)/$(SRCDIR)/sistemaTest.cpp -o $(TESTSDIR)/$(BUILDDIR)/sistemaTest

cleanTests:
	$(RM) -r $(TESTSDIR)/$(BUILDDIR)/* $(TARGET)

clean: cleanTests
	$(RM) -r $(BUILDDIR)/* $(TARGET)

doxy:
	doxygen doxyconfig

$(shell mkdir -p AI debug/AI Scripting debug/Scripting \
	out/vcmi/lib out/vcmi/server out/vcmi/AI/StupidAI \
	out/vcmi/AI/GeniusAI out/vcmi/client out/vcmi/Scripting/ERM)
$(shell rm -f ../../../obj/local/armeabi/libvcmi.so)

LOCAL_PATH=$(shell dirname $0)
LOCAL_PATH=`cd $LOCAL_PATH && pwd`

GCC_PREFIX=$(if $(shell which ndk-build | grep 'android-ndk-r5'),arm-linux-androideabi,arm-eabi)

SOURCES_LIB=$(wildcard vcmi/lib/*.cpp vcmi/CConsoleHandler.cpp vcmi/CThreadHelper.cpp)
OBJS_LIB=$(patsubst %.cpp, out/%.o, $(SOURCES_LIB))

SOURCES_SERVER=$(wildcard vcmi/server/*.cpp)
OBJS_SERVER=$(patsubst %.cpp, out/%.o, $(SOURCES_SERVER))

SOURCES_STUPIDAI=$(wildcard vcmi/AI/StupidAI/*.cpp)
OBJS_STUPIDAI=$(patsubst %.cpp, out/%.o, $(SOURCES_STUPIDAI))

SOURCES_GENIUSAI=$(filter-out %/ExpertSystem.cpp, $(wildcard vcmi/AI/GeniusAI/*.cpp))
OBJS_GENIUSAI=$(patsubst %.cpp, out/%.o, $(SOURCES_GENIUSAI))

SOURCES_ERM=$(wildcard vcmi/Scripting/ERM/*.cpp)
OBJS_ERM=$(patsubst %.cpp, out/%.o, $(SOURCES_ERM))

all: AndroidData/vcmiserver0

AndroidData/vcmiserver0: vcmiserver.zip
	rm -f AndroidData/vcmiserver*
	split -b 1048576 -d -a 1 $< AndroidData/vcmiserver
	cp -f AndroidData/vcmiserver* ../../../assets

vcmiserver.zip: vcmiserver AI/libGeniusAI.so AI/libStupidAI.so Scripting/libvcmiERM.so
	rm -f $@
	zip -r $@ $^

$(OBJS_SERVER) $(OBJS_LIB) $(OBJS_GENIUSAI) $(OBJS_STUPIDAI) $(OBJS_CLIENT) $(OBJS_ERM): out/%.o: %.cpp
	../setEnvironment.sh sh -c \
	"$(GCC_PREFIX)-g++ \
	-c \$$CXXFLAGS -Ivcmi -Ivcmi/lib \
	-DDATA_DIR=\\\"/sdcard/app-data/eu.vcmi\\\" \
	-DBIN_DIR=\\\"/data/data/eu.vcmi/files\\\" \
	-DLIB_DIR=\\\"/data/data/eu.vcmi/files\\\" \
	-DWITH_AVCODEC_DECODE_VIDEO2=1 \
	-Wstrict-aliasing -Wcast-align -Wpointer-arith -Waddress \
	$< -o $@"
#	-Werror=strict-aliasing -Werror=cast-align -Werror=pointer-arith -Werror=address

vcmiserver: $(OBJS_SERVER) $(OBJS_LIB)
	env BUILD_EXECUTABLE=1 NO_SHARED_LIBS=1 ../setEnvironment.sh sh -c \
	"$(GCC_PREFIX)-g++ \
	$^ -o $@ \
	\$$LDFLAGS -L. \
	-lboost_filesystem -lboost_iostreams -lboost_system -lboost_thread" && \
	cp $@ debug/$@ && \
	$(GCC_PREFIX)-strip $@

LINK_LIB= \
	env BUILD_EXECUTABLE=1 NO_SHARED_LIBS=1 ../setEnvironment.sh sh -c \
	"$(GCC_PREFIX)-g++ \
	$^ -o $@ \
	-shared \$$LDFLAGS -L. \
	-lboost_filesystem -lboost_iostreams -lboost_system -lboost_thread" && \
	cp $@ debug/$@ && \
	$(GCC_PREFIX)-strip $@

.PHONY: -lvcmi
-lvcmi: libvcmi.so

AI/libGeniusAI.so: $(OBJS_GENIUSAI) -lvcmi
	$(LINK_LIB)

AI/libStupidAI.so: $(OBJS_STUPIDAI) -lvcmi
	$(LINK_LIB)

Scripting/libvcmiERM.so: $(OBJS_ERM) -lvcmi
	$(LINK_LIB)

libvcmi.so: $(OBJS_LIB)
	$(LINK_LIB)

clean:
	rm -rf out debug *.so vcmiserver* AndroidData/vcmiserver* libapplication.so AI Scripting

.PHONY: clean


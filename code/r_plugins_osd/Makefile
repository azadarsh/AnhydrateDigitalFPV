LDFLAGS=-lrt -lpcap -lpthread
CPPFLAGS=-Wall -O2
CFLAGS := $(CFLAGS) -Wall -O2 
RELEASE_DIR = ../../

all: Anhydrate_plugin my_plugin Anhydrate_plugin_gauge_speed Anhydrate_plugin_gauge_altitude Anhydrate_plugin_gauge_ahi Anhydrate_plugin_gauge_heading

osd_plugins_utils.o: ../public/utils/osd_plugins_utils.c
	gcc -c -o $@ $< $(CPPFLAGS)

core_plugins_utils.o: ../public/utils/core_plugins_utils.c
	gcc -c -o $@ $< $(CPPFLAGS)

%.o: %.cpp
	g++ $(CFLAGS) -std=gnu++11 -c -o $@ $< $(CPPFLAGS)  


Anhydrate_plugin: Anhydrate_plugin_osd_ahi.o osd_plugins_utils.o core_plugins_utils.o
	gcc Anhydrate_plugin_osd_ahi.o -shared -Wl,-soname,Anhydrate_ahi_plugin.so.1 -o Anhydrate_ahi_plugin.so.1.0.1 -lc
	cp -f Anhydrate_ahi_plugin.so.1.0.1 $(RELEASE_DIR)
	$(info Copy Anhydrate_ahi_plugin done)
	$(info ----------------------------------------------------)

Anhydrate_plugin_gauge_speed: Anhydrate_plugin_gauge_speed.o osd_plugins_utils.o
	gcc Anhydrate_plugin_gauge_speed.o -shared -Wl,-soname,Anhydrate_plugin_gauge_speed.so.1 -o Anhydrate_plugin_gauge_speed.so.1.0.1 -lc
	cp -f Anhydrate_plugin_gauge_speed.so.1.0.1 $(RELEASE_DIR)
	$(info Copy Anhydrate_plugin_gauge_speed done)
	$(info ----------------------------------------------------)

Anhydrate_plugin_gauge_altitude: Anhydrate_plugin_gauge_altitude.o osd_plugins_utils.o core_plugins_utils.o
	gcc Anhydrate_plugin_gauge_altitude.o osd_plugins_utils.o core_plugins_utils.o -shared -Wl,-soname,Anhydrate_plugin_gauge_altitude.so.1 -o Anhydrate_plugin_gauge_altitude.so.1.0.1 -lc
	cp -f Anhydrate_plugin_gauge_altitude.so.1.0.1 $(RELEASE_DIR)
	$(info Copy Anhydrate_plugin_gauge_altitude done)
	$(info ----------------------------------------------------)

Anhydrate_plugin_gauge_ahi: Anhydrate_plugin_gauge_ahi.o osd_plugins_utils.o core_plugins_utils.o
	gcc Anhydrate_plugin_gauge_ahi.o -shared -Wl,-soname,Anhydrate_plugin_gauge_ahi.so.1 -o Anhydrate_plugin_gauge_ahi.so.1.0.1 -lc
	cp -f Anhydrate_plugin_gauge_ahi.so.1.0.1 $(RELEASE_DIR)
	$(info Copy Anhydrate_plugin_gauge_ahi done)
	$(info ----------------------------------------------------)

Anhydrate_plugin_gauge_heading: Anhydrate_plugin_gauge_heading.o osd_plugins_utils.o core_plugins_utils.o
	gcc Anhydrate_plugin_gauge_heading.o -shared -Wl,-soname,Anhydrate_plugin_gauge_heading.so.1 -o Anhydrate_plugin_gauge_heading.so.1.0.1 -lc
	cp -f Anhydrate_plugin_gauge_heading.so.1.0.1 $(RELEASE_DIR)
	$(info Copy Anhydrate_plugin_gauge_heading done)
	$(info ----------------------------------------------------)

my_plugin: my_plugin_source.o
	gcc my_plugin_source.o -shared -Wl,-soname,my_plugin.so.1 -o my_plugin.so.1.0.1 -lc
	cp -f my_plugin.so.1.0.1 $(RELEASE_DIR)

clean:
	rm -f Anhydrate_ahi_plugin.so.* Anhydrate_plugin_gauge_speed.so.* Anhydrate_plugin_gauge_altitude.so.* Anhydrate_plugin_gauge_ahi.so.* Anhydrate_plugin_gauge_heading.so.* my_plugin.* *.o


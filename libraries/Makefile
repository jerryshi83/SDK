# /*
OBJS := itead_LCD4Bit_mod.o
OBJS += itead_GFX.o
OBJS += itead_SSD1306.o


all: libiteadmodule.so

libiteadmodule.so: $(OBJS)
	$(SDKCPPCOMPILE) -fpic -shared -o $@ $^

$(OBJS):
	$(MAKE) -C $(subst .o,,$@) $@
	mv $(subst .o,,$@)/$@ ./

clean:
	rm -rf  $(OBJS) libiteadmodule.so

.PHONY: all $(OBJS)
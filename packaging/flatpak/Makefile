TEMP_DIR := ./temp
REPO = $(TEMP_DIR)/repo
BUILD = $(TEMP_DIR)/build
STATE = $(TEMP_DIR)/state
MANIFEST = org.flatpak.susterm

build:
	flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo --user
	flatpak-builder -v --repo=$(REPO) --state-dir=$(STATE) $(BUILD) $(MANIFEST).yml --force-clean --user --install-deps-from=flathub
	flatpak build-bundle -v $(REPO) $(MANIFEST).flatpak $(MANIFEST) --runtime-repo=https://flathub.org/repo/flathub.flatpakrepo

install:
	flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo --user
	flatpak-builder -v --repo=$(REPO) --state-dir=$(STATE) $(BUILD) $(MANIFEST).yml --force-clean --user --install-deps-from=flathub --install

clean:
	rm -rf $(TEMP_DIR)
	rm *.flatpak

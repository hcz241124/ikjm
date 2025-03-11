py3 ?= python3.11
init_env:
	$(py3) -m vene .env

.PHONY: init_env
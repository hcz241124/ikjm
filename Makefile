py3 ?= python3
init_env:
	$(py3) -m venv .env

.PHONY: init_env
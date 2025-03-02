CFORMAT_FILES= -name "*.cpp" -o -name "*.h" -o -name "*.tpp"

_cformat_n:
	$(call run_cformat,-n)

_cformat_i:
	$(call run_cformat,-i)

_start_style: _cformat_n _cformat_i

_start_style_ci:
	find . \( \( $(CFORMAT_FILES) \) \) -print0 | xargs -0 -n 1 clang-format -style=$(CODE_STYLE) --Werror -n --verbose

define run_cformat
	@find . -type f \( $(CFORMAT_FILES) \) -exec clang-format -style=$(CODE_STYLE) $(1) {} \;
endef

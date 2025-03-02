# Flawfinder — инструмент для статического анализа кода, который помогает разработчикам находить потенциальные уязвимости в исходном коде, в проектах на C и C++.

FIND_FILES=$(shell find . -type f \( -name "*.tpp" -o -name "*.cpp" -o -name "*.h" \) -not -path "./tests/*")

_start_flawfinder:
	@mkdir -p report/flawfinder
	@. /root/venv/bin/activate && flawfinder --minlevel=0 --columns --context --html $(FIND_FILES) > report/flawfinder/index.html

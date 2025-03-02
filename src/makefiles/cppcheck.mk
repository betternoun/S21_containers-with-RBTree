CPPCHECK_FLAGS=--enable=all --language=c++ --std=c++17 --check-level=exhaustive

_cppcheck_dir_report:
	@mkdir -p report/cppcheck

_cppcheck:
	@find . \( -name "*.cpp" -o -name "*.h" -o -name "*.tpp" \) -not -path "./tests/*" -exec cppcheck $(CPPCHECK_FLAGS) {} +

# Используется для принудительного анализа всех возможных конфигураций предварительной обработки.
_cppcheck_force:
	$(eval CPPCHECK_FLAGS += --force)

# Используется для подавления предупреждений о системных заголовочных файлах, которые не найдены во время анализа.
_cppcheck_suppress:
	$(eval CPPCHECK_FLAGS += --suppress=missingIncludeSystem)

# Подавление неиспользуемых функций
_cppcheck_unused_function:
	$(eval CPPCHECK_FLAGS += --suppress=unusedFunction)

# Используется для включения предупреждений о потенциальных проблемах, которые не могут быть однозначно определены.
_cppcheck_inconclusive:
	$(eval CPPCHECK_FLAGS += --inconclusive)

# Позволяет автоматическим системам CI обнаружить наличие проблем.
_cppcheck_ci:
	$(eval CPPCHECK_FLAGS += --error-exitcode=1)

# Включить текущую директорию для поиска заголовочных файлов.
_cppcheck_h:
	$(eval CPPCHECK_FLAGS += -I .)

# Отчет сохранить в файл
_cppcheck_report: _cppcheck_dir_report
	$(eval CPPCHECK_FLAGS += --checkers-report=report/cppcheck/report.log)

# Сохранить вывод анализа в файл для генерации html
_cppcheck_xml: _cppcheck_dir_report
	$(eval CPPCHECK_FLAGS += --xml-version=2 --output-file=report/cppcheck/report.xml)

# Создает HTML отчет в директории report/cppcheck
_cppcheck_html: _cppcheck_dir_report _cppcheck_xml _cppcheck
	@cppcheck-htmlreport --file=report/cppcheck/report.xml --report-dir=report/cppcheck --source-dir=.
	@rm -rf report/cppcheck/report.xml

# Выведет информацию о любых проблемах в конфигурации, которые могут мешать анализу.
_cppcheck_config:
	$(eval CPPCHECK_FLAGS += --check-config .)

_start_cppcheck_report: _cppcheck_force _cppcheck_inconclusive _cppcheck_h _cppcheck_suppress _cppcheck_report _cppcheck_html

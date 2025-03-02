# Lizard — инструмент для анализа кода, который помогает разработчикам измерять сложность и качество их программного обеспечения.

_start_lizard:
	@mkdir -p report/lizard
	@. /root/venv/bin/activate && lizard --html . -x "./tests/*" > report/lizard/index.html

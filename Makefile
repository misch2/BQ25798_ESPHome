.PHONY: jinja2

jinja2: 
	@echo "Generating jinja2 templates..."
	@echo "--------------------------------"
	@py process_templates.py
	@echo "--------------------------------"
	@echo "All jinja2 templates have been generated."
	@echo "--------------------------------"

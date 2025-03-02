INSTALL_H=$(wildcard $(SRCDIR)/$(SUBPROJECT)/*/*.h) $(SRCDIR)/s21_$(SUBPROJECT).h
INSTALL_TPP=$(wildcard $(SRCDIR)/$(SUBPROJECT)/*/*.tpp)

_install: $(INSTALL_H) $(INSTALL_TPP)
	@mkdir -p $(LIBDIR)
	@for file in $(INSTALL_H) $(INSTALL_TPP); do \
		dir=$$(dirname "$$file"); \
		dest_dir=$(LIBDIR)/$${dir#$(SRCDIR)/}; \
		mkdir -p "$$dest_dir"; \
		cp "$$file" "$$dest_dir/"; \
	done

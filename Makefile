metaL.log: metaL.py metaL.ml
	python $^ > $@
	
update:
	git pull
	cd wiki ; git pull
	rsync wiki/Home.md README.md

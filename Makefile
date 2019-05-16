metaL.log: metaL.py metaL.ml
	python $^ > $@
	
update:
	cd wiki ; git pull
	rsync wiki/Home.md README.md

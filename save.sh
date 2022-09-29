for filename in ~/Documents/piscine/*; do
	cp -r $filename ~/Documents/saves
	rm -rf $filename/.git
	cd ~/Documents/saves 
	git add .
	git commit -m "Pressed the panic button"
	git push
done

class core {
	private:
		int total; //a classic example of mkaing a variable in advance; you'll never use it :(
		
	public:
		//part one
		int area(std::string text) {
			if (text.find('x')) {
				int l = stoi(text.substr(0, text.find('x')));
				text = text.substr(text.find('x') + 1, text.length()); //another pointless error that I spent 30 minutes fixing lies here.
				int w = stoi(text.substr(0, text.find('x')));
				text = text.substr(text.find('x') + 1, text.length()); //and here
				int h = stoi(text.substr(0, text.length()));
				
				unsigned int surface = (2*(l*w)) + (2*(w*h)) + (2*(h*l));
				unsigned int slack = std::min((l*w), std::min((w*h), (h*l)));
				
				return surface + slack;
			} else {
				return 0;
			}
			
		}
		
		//part two
		int ribbon(std::string text) {
			if (text.find('x')) {
				int l = stoi(text.substr(0, text.find('x')));
				text = text.substr(text.find('x') + 1, text.length()); 
				int w = stoi(text.substr(0, text.find('x')));
				text = text.substr(text.find('x') + 1, text.length()); 
				int h = stoi(text.substr(0, text.length()));
				
				int ribbon = std::min(((2*l) + (2*w)), std::min((2*w) + (2*h), (2*h) + (2*l)));
				int bow = (l*w*h);
				
				return ribbon + bow ;
			} else {
				return 0;
			}
		}
};

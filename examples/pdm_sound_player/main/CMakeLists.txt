set(requires
    driver
)

idf_component_register( 
    SRCS 
	    main.cpp
    EMBED_FILES "../sound_files/test.wav"
    EMBED_FILES "../sound_files/test.mp3"
    REQUIRES ${requires}
)

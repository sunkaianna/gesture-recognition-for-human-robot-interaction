Gesture Recognition For Human-Robot Interaction
===============================================

AUTHOR
--------------------------------------
Aravinth Panchadcharam < http://www.aravinth.info >


Abstract
--------------------------------------
<p align="justify">
Human-robot interaction (HRI) has been a topic of both science fiction and academic speculation even before any robots
existed. HRI research is focusing to build an intuitive and easy communication with the robot through speech, gestures,
and facial expressions. The use of hand gestures provides an attractive alternative to complex interfaced devices for HRI.
In particular, visual interpretation of hand gestures can help in achieving the ease and naturalness desired for HRI.
This has motivated a very active research concerned with computer vision-based analysis and interpretation of hand gestures.
Important differences in the gesture interpretation approaches arise depending on whether 3D based model or appearance
based model of the gesture is used.
</p>

<p align="justify">
In this project, we attempt to implement the hand gesture recognition for robots with modeling, training, analyzing and
recognizing gestures based on computer vision and machine learning techniques. Additionally, 3D based gesture modeling
with skeletal points tracking will be used. As a result, on the one side, gestures will be used command the robot to
execute certain actions and on the other side, gestures will be translated and spoken out by the robot.
</p>

<p align="justify">
We further hope to provide a platform to integrate Sign Language Translation to assist people with hearing and speech
disabilities. However, further implementations and training data are needed to use this platform as a full fledged
Sign Language Translator.
</p>

![Architecture](./document/diagram/hri-architecture.png "Architecture")


Motivation
--------------------------------------

<p align="justify">
Huge influence of computers in society has made smart devices, an important part of our lives. Availability and
affordability of such devices motivated us to use them in our day-to-day living. The list of smart devices includes
personal automatic and semi-automatic robots which are also playing a major role in our household. For an instance,
Roomba is an autonomous robotic vacuum cleaners that automatically cleans the floor and goes to its charging station
without human interaction.
</p>

<p align="justify">
Interaction with smart devices has still been mostly through displays, keyboards, mouse and touch interfaces.
These devices have grown to be familiar but inherently limit the speed and naturalness with which we can interact with
the computer.  Usage of robots for domestic and industrial purposes has been continuously increasing.
Thus in recent years, there has been a tremendous push in research toward an intuitive and easy communication with the
robot through speech, gestures and facial expressions.
</p>

<p align="justify">
Tremendous progress had been made in speech recognition and several commercially successful speech interfaces are
available. However, speech recognition systems have certain limitations such as misinterpretation due to various accents
and background noise interference. It may not be able to differentiate between your speech, other people talking and
other ambient noise, leading to transcription mix-ups and errors.
</p>

<p align="justify">
Furthermore, there has been an increased interest in recent years in trying to introduce other human-to-human
communication modalities into HRI. This includes a class of techniques based on the movement of the human arm and hand,
or hand gestures. The use of hand gestures provides an attractive alternative for Human-robot interaction than
the conventional cumbersome devices.
</p>


Design
--------------------------------------

###Sensing
<p align="justify">
3D camera records 30 frames of color image as well as depth image per second and outputs as a data package.
Figure shows the single frame of depth image taken from Microsoft Kinect where darker gray values represent the farther distance and lighter gray values represent the closer distance from the camera.
</p>
![Depth Image](./document/diagram/depth.png "Depth Image")


###Feature Extraction
<p align="justify">
Output package from sensor data will be inputted to feature detection and extraction unit.
OpenNI is a software component that will track the anatomical landmarks of the human body from the package and extract significant joint angle parameters along with segment length and present them three dimensionally as shown in the figure.
Finally, only joints of both the arms will be picked out from the array of features, since it will be the significant joints needed for hand gesture recognition.
</p>
![Skeleton](./document/diagram/depth-skeleton.png "Skeleton")


###Modeling and Classification
<p align="justify">
In order to use this hand recognition system, all chosen gestures must be observed and the system must be trained.
Therefore, a set of simple gestures will be chosen and observed for training. Each gesture is isolated in time and gesticulated for certain duration. However, sensors provides 30 frames of discrete states of gesture per second.
</p>
![States](./document/diagram/ges-states.png "States")

<p align="justify">
For example, a gesture is gesticulated by simply drawing a circle in the air and its ideal states are shown in the figure.
It will be  as a position of hand passing through 8 states of the circle. Each state is a point in space with x, y and z axis data.
This approach makes it possible for us to reduce our observation data to sequential 3D points and focus on the recognition task without processing all those pixels.
Each trained model can then be used to determine with what probability a given gesture appears in test data.
Therefore, the trained Hidden Markov models will be used to recognize gestures.
</p>

###Gesture Analysis and Recognition
<p align="justify">
This step contains the analysis of gesticulated gesture and finding out the likelihood of that gesture with trained data, known as gesture recognition.
Figure contains colored rings of noisy data of gestures that represent instances of a real circle gesture. Sensing and feature detection module will produce 60 observations of the circle gesture for 2 seconds, since the depth camera records at 30 frame per second. To decide whether a given set of 60 observations contains a circle gesture, we need to first determine the likelihood that the hand passed through the eight states of the gesture in the expected sequence.
</p>

![Training](./document/diagram/ges-train.png "Training")

<p align="justify">
Discrete HMM is a finite set of possible output symbols and a sequence of hidden states which reveal some probability.
To reduce our real gesture data to a workable number of discrete output symbols and states, we can use any clustering algorithm to cluster the 3D points of all our training data of circle gesture into clusters and label them.
That is to say, every point in the training data represents an output symbol that is closely tied to one of the 8 true states of the model.
</p>

<p align="justify">
Looking at the labeled data, we can estimate how likely it is that a hand passed through the 8 clusters in the same sequence as a circle gesture and if the likelihood is high enough, then the gesture is considered to be recognized.
</p>

![ges-rec](./document/diagram/ges-rec.png "Recognition" )

###Human-Robot Interaction
<p align="justify">
Finally, the recognized gesture will be interpreted by NAO to execute a specified task.
For example. circle gesture would ask NAO to turn around. However, NAO will also be available in Translation Mode by using ALTextToSpeech Library to translate the recognized gesture.
</p>

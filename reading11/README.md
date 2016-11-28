Reading 11
==========

Michael McRoskey
----------------

---

**1) What problem is the Google File System trying to solve?**

The Google File System is trying to provide reliable, efficient access to a bunch of data. However, it wants to do this using commodity hardware. So they could of course spend $$$ to do the same thing (have ridiculously amazing hardware in the process) or incorporate some fancy, inexpensive software (an abstraction layer on top of super inexpensive hardware) to still search a huge collection of files.

- How does it solve this problem?

Okay so it uses a master-worker configuration. Imagine the master is like a plower and he needs something(s) to pull the plow (sorry for the bad example, but trust me it makes sense). So he could use a huge ox or a thousand chickens. Google says, "a thousand chickens!" So the plower needs to sort of control each of the chickens. ~Similarly~... the Google File system is distributed and utilizes chunks as the chickens (aliteration woo). This is great because it's very scalable, like you can just add more chunks/chickens.

- Describe how data is stored in Google File System.

So someone requests a file which gets passed to a GFS Master, which is basically the plower. Files are broken into chunks which are distributed among chunk servers. Each chunk is given a chunk index, which is requested by the person. GFS Master then requests the proper chunk handle which will produce the different locations (GFS Chunkservers) where the chunks reside. Chunk data is then sent back to the client.

- Based on what you read, describe some data structures or algorithms that would be used in Google File System.

I mean I would probably have used some form of Dijkstra's to efficiently and quickly get to a node. I think a node-based implementation would work the best as each of the chunks are nodes, thus some sort of a tree. I think some hashing would make sense to process client input and determine node location. Then I would use a path-algorithm to find the fastest path to a particular node.

**2) What problem is Map-Reduce trying to solve?**

Map-Reduce is trying to solve the problem of processing HUGE datasets efficiently. In other words, it uses filtering to reduce the results of say, a search. It uses abstraction to hide away all the gritty details of fault-tolerance (when a node fails), proper distribution (so its balanced properly), and ~parallelizability~ (long word, but means multiple instances of the same element/process).

- How does it solve this problem?

The main solution is utilizing parallelizability, which means like concurrently computing code without dependencies to speed up computation. So it can split a problem apart where there are no dependencies and compute each part at the same time. This utilizes lots of functional programming!

- Describe the three phases of a typical Map-Reduce workflow.

All of this is controlled by the Master, similar to GFS. It basically does map...shuffle...reduce. That means it maps input data, a sort of filtering process. There's this shuffle phase that reorders "intermediate" data. Reduce then takes all the results and combines certain parts and sorts it so that it's meaningful in order to produce an output.

- Based on what you read, describe some data structures or algorithms that would be used in Map-Reduce.

I think I would definitely use a map to store inputs initially. For my reduce function, I might implement some sort of a sorting function to group similar elements together so that they can be processed separately.
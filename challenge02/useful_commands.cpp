std::cout << "List Size: " << mylist.size() << std::endl;
    std::cout << "List Items:" << std::endl;
    for (size_t i = 0; i < mylist.size(); i++) {
        std::cout << "List at " << i << " " << mylist.at(i) << std::endl;
    }

    std::cout << "**** Insert" << std::endl;
    auto head = mylist.front();
    mylist.insert(head, NITEMS + 1);
    mylist.insert(head, NITEMS + 2);
    mylist.insert(head->next->next, NITEMS + 3);

    std::cout << "List Size: " << mylist.size() << std::endl;
    std::cout << "List Items:" << std::endl;
    for (size_t i = 0; i < mylist.size(); i++) {
        std::cout << "List at " << i << " " << mylist.at(i) << std::endl;
    }

    // List copy
    std::cout << "**** Copy" << std::endl;
    List<int> copy(mylist);

    std::cout << "Copy Size: " << copy.size() << std::endl;
    std::cout << "Copy Items:" << std::endl;
    for (size_t i = 0; i < copy.size(); i++) {
        std::cout << "Copy at " << i << " " << copy.at(i) << std::endl;
    }

    // List assignment
    std::cout << "**** Assignment" << std::endl;
    copy.push_back(NITEMS + 4);
    mylist = copy;
    std::cout << "List Size: " << mylist.size() << std::endl;
    std::cout << "List Items:" << std::endl;
    for (size_t i = 0; i < mylist.size(); i++) {
        std::cout << "List at " << i << " " << mylist.at(i) << std::endl;
    }

    // Erase
    std::cout << "**** Erase" << std::endl;
    mylist.erase(mylist.front());
    mylist.erase(mylist.front()->next);
    std::cout << "List Size: " << mylist.size() << std::endl;
    std::cout << "List Items:" << std::endl;
    for (size_t i = 0; i < mylist.size(); i++) {
        std::cout << "List at " << i << " " << mylist.at(i) << std::endl;
    }
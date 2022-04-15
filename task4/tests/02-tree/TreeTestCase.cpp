//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include <filesystem>

using std::filesystem::path;

TEST(Test_1, test) {
	FileNode f1 ;
	FileNode f2 ;
	FileNode f3 ;
	FileNode f0 ; 
	FileNode f01 ;
	std::vector<FileNode> chil={f01 , f0};
        f1.name = "sMTH" ;
        f1.is_dir = true;
        f1.children = chil;
        
        f2.name = "sMTH" ;
        f2.is_dir = true;
        f2.children = chil;
        
        f3.name = "text.txt" ;
        f3.is_dir = false;
	
	ASSERT_TRUE(f1 == f2);
	ASSERT_FALSE(f2 == f3);
	
}

TEST(Test2 ,test){
    
    FileNode node;
    FileNode node1;
    FileNode node2;
    FileNode node3;
    node3.name = "name3";
    node3.is_dir = false;
    node3.children = {};
    node1.name = "name1";
    node1.is_dir = true;
    node1.children = {node2};
    node2.name = "name2";
    node2.is_dir = true;
    node2.children = {node3};
    node.name = "name";
    node.is_dir = true;
    node.children = {node1, node2};
    FilterEmptyNodes(node,path(node.name));
    ASSERT_FALSE(node.children.empty());
    ASSERT_TRUE(node1.is_dir);
}

TEST(Test3,test){
    ASSERT_THROW(GetTree("../dgjs", true),std::invalid_argument);
    ASSERT_THROW(GetTree("../CMakeLists", true), std::invalid_argument);
    ASSERT_TRUE(GetTree("..", true).is_dir);
    FileNode node = GetTree("..", true);
    ASSERT_TRUE(node.children[1].is_dir);
    ASSERT_EQ("..",node.name);
    FileNode node1 ;
    node1.name = "dfhwf";
    node1.is_dir = false;
    ASSERT_THROW(GetTree(node1.name, true), std::invalid_argument);
}

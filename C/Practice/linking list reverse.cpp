node *reverse(node *head, node *tail){
  	node *previous=NULL;
  	node *current=head;
  	node *preceding=current->next;
  	while(preceding!=NULL){
  		current->next=previous;
  		previous=current;
  		current=preceding;
  		preceding=preceding->next;
	  }
	  current->next=previous;
	  
    return *current;
}

